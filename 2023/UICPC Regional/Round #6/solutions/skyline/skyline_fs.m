function skyline(infile, figNr, animationDuration)
% infile = skyline.X.in
% figNr = [FigureWithLine FigureWithBuildings], e.g. [1, 2]
% animationDuration = Maximum total animation time
    if(nargin < 2)
        figNr = [0 0];
    elseif(length(figNr) < 2)
        figNr = [figNr 0];
    end
    
    fh = fopen(infile);
    N = fscanf(fh, '%d', 1);
    if(~isempty(figNr))
        cm = lines(N);
        if(nargin < 3)
            sleepTime = min(0.5, 10/N);
        else
            sleepTime = animationDuration/N;
        end
    end
    b.x1 = 0;
    b.y1 = 0;
    b.x2 = 0;
    b.y2 = 0;
    buildings(1:N) = b;
    xs = zeros(1, 2*N);
    for i=1:N
        d = fscanf(fh, '%d', 4);
        buildings(i).x1 = d(1);
        buildings(i).y1 = d(2);
        buildings(i).x2 = d(3);
        buildings(i).y2 = d(4);
        xs(2*i-1) = buildings(i).x1;
        xs(2*i) = buildings(i).x2;
    end
    fclose(fh);

    % Cross each line with each other, store the x-values
    for i=1:N
        for j=i+1:N
            x = Crossing(buildings(i), buildings(j));
            if(x > -1)
                xs(end+1) = x; %#ok<AGROW>
            end
        end
    end
    % xs = sort(xs);
    xs = unique(xs);
    yleft = zeros(1, length(xs));
    yright = zeros(1, length(xs));

    xplot = zeros(N, 2*length(xs));
    yplot = zeros(N, 2*length(xs));
    for i=1:N
        b = buildings(i);
        ownArea = AreaBelow(b.x1, b.y1, b.x2, b.y2);
        visibleArea = 0;

        ifirst = find(xs == b.x1);
        ilast = find(xs == b.x2);
        ynext = (xs(ifirst)-b.x1)/(b.x2-b.x1) * (b.y2-b.y1) + b.y1;
        for icur=ifirst:ilast-1
            ycur = ynext;
            inext = icur+1;
            xcur = xs(icur);
            xnext = xs(icur+1);
            ynext = (xnext-b.x1)/(b.x2-b.x1) * (b.y2-b.y1) + b.y1;
            if(ycur >= yright(icur) - eps && ynext >= yleft(inext) - eps)
                visibleArea = visibleArea + AreaBelow(xcur, ycur, xnext, ynext);
                visibleArea = visibleArea - AreaBelow(xcur, yright(icur), xnext, yleft(inext));
                yright(icur) = ycur; %#ok<AGROW>
                yleft(inext) = ynext; %#ok<AGROW>
            end
        end
        %cout << setprecision(8) << visibleArea / ownArea << endl;
        fprintf('%.6f\n', visibleArea / ownArea);

        if(~isempty(figNr))
            x = [xs; xs];
            y = [yleft; yright];
            xplot(i,:) = x(:);
            yplot(i,:) = y(:);
            
            % Skyline
            if(figNr(1) ~= 0)
                figure(figNr(1));
                clf();
                plot(xplot(i,:), yplot(i,:), 'k');
                xlim([min(xs)-1 max(xs)+1]);
                ylim([0 max([buildings.y1 buildings.y2])]);
            end

            % All buildings
            if(figNr(2) ~= 0)
                figure(figNr(2));
                clf();
                hold('on');
                for j=i:-1:1
                    bc = buildings(j);
                    x = [bc.x1 bc.x1 bc.x2 bc.x2];
                    y = [0 bc.y1 bc.y2 0];
                    fill(x, y, cm(j,:), 'FaceAlpha', 0.8);
                end
                % Must do this to get the latest fill() to be painted
                % correctly
                fill(0, 0, [0 0 0]);
                xlim([min(xs)-1 max(xs)+1]);
                ylim([0 max([buildings.y1 buildings.y2])]);
            end
            drawnow();
            pause(sleepTime);
        end
    end
end

% Returns x, < -1 if no crossing
function x = Crossing(b1, b2)
    x = -2;
    if(b1.x2 <= b2.x1 || b2.x2 <= b1.x1)
        return;
    end
    % Do they cross
    x1 = max(b1.x1, b2.x1);
    x2 = min(b1.x2, b2.x2);
    y11 = (x1-b1.x1)/(b1.x2-b1.x1) * (b1.y2-b1.y1) + b1.y1;
    y12 = (x2-b1.x1)/(b1.x2-b1.x1) * (b1.y2-b1.y1) + b1.y1;
    y21 = (x1-b2.x1)/(b2.x2-b2.x1) * (b2.y2-b2.y1) + b2.y1;
    y22 = (x2-b2.x1)/(b2.x2-b2.x1) * (b2.y2-b2.y1) + b2.y1;
    if(y11 >= y21 - eps && y12 >= y22 - eps)
        return;
    end
    if(y11 - eps <= y21 && y12 - eps <= y22)
        return;
    end

    % Find x of the crossing
    f1 = b1.y2 - b1.y1;
    g1 = b1.x1 - b1.x2;
    h1 = f1*b1.x1 + g1*b1.y1;
    f2 = b2.y2 - b2.y1;
    g2 = b2.x1 - b2.x2;
    h2 = f2*b2.x1 + g2*b2.y1;
    det = f1*g2 - f2*g1;
    x = (g2*h1 - g1*h2)/det;
end

function area = AreaBelow(x1, y1, x2, y2)
    area = (y1 + y2) * (x2 - x1) * 0.5;
end
