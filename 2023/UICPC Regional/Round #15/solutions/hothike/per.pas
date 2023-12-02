program hothike;

uses sysutils, math;

var
   n, d, t, i :longint;
   X :array[1..50] of longint;
begin
   read(n);
   for i := 1 to n do read(X[i]);
   t := 50;
   for i := 1 to n-2 do
      begin
         if max(X[i], X[i+2]) < t then
            begin
               d := i;
               t := max(X[i], X[i+2]);
            end;
      end;
   writeln(IntToStr(d) + ' ' + IntToStr(t));
end.
