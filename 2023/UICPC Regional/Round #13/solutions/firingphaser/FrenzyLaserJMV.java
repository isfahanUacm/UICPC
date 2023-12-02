import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.Scanner;

import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.pow;
import static java.lang.Math.signum;
import static java.lang.Math.sqrt;

public class FrenzyLaserJMV {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), l = in.nextInt();
        Room[] rooms = new Room[n];
        for (int i = 0; i < n; i++)
            rooms[i] = new Room(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());

        int max = 1;
        for (Room anchor : rooms) {
            for (Point2D focus : anchor.corners) {
                for (Room origin : rooms) {
                    for (Line2D source : origin.walls) {
                        boolean vertical = source.getX1() == source.getX2();
                        for (Room destination : rooms) {
                            for (Point2D target : destination.corners) {
                                if (target == focus)
                                    continue;

                                double  dx = target.getX() - focus.getX(),
                                        dy = target.getY() - focus.getY();

                                if ((dx == 0 && vertical) || (dy == 0 && ! vertical))
                                    continue;

                                max = max(max, hits(source, dx, dy, l, focus, rooms));
                            }

                            for (Line2D target : destination.walls) {
                                if (vertical == (target.getX1() == target.getX2()))
                                    continue;

                                double  dx = vertical ? focus.getX() - source.getX1() : target.getX1() - focus.getX(),
                                        dy = vertical ? target.getY1() - focus.getY() : focus.getY() - source.getY1();

                                if (dx == 0 || dy == 0)
                                    continue;

                                max = max(max, hits(source, dx, pow(abs(dx * dx * dy), 1.0 / 3) * signum(dy), l, focus, rooms));
                            }
                        }
                    }
                }
            }
        }
        System.out.println(max);
    }

    /** Rooms hit by the ray starting in source, of length l, with direction (dx, dy), along a line through focus. */
    static int hits(Line2D source, double dx, double dy, double l, Point2D focus, Room[] rooms) {
        double sx, sy;
        if (source.getX1() == source.getX2()) {
            sx = source.getX1();
            sy = focus.getY() - (dy / dx) * (focus.getX() - sx);
        }
        else {
            sy = source.getY1();
            sx = focus.getX() - (dx / dy) * (focus.getY() - sy);
        }
        double  ax = dx / sqrt(dx * dx + dy * dy),
                ay = dy / sqrt(dx * dx + dy * dy);
        Line2D laser = new Line2D.Double(sx, sy, sx + ax * l, sy + ay * l);

        int hits = 0;
        for (Room room : rooms) {
            if (laser.intersects(room))
                hits++;
        }
        return hits;
    }


    static class Room extends Rectangle2D.Double {

        final Point2D.Double southWest, southEast, northEast, northWest;
        final Point2D.Double[] corners;
        final Line2D.Double west, east, south, north;
        final Line2D.Double[] walls;

        Room(int x1, int y1, int x2, int y2) {
            super(x1 - 1e-7, y1 - 1e-7, x2 - x1 + 2e-7, y2 - y1 + 2e-7);

            southWest = new Point2D.Double(x1, y1);
            southEast = new Point2D.Double(x2, y1);
            northEast = new Point2D.Double(x2, y2);
            northWest = new Point2D.Double(x1, y2);
            corners = new Point2D.Double[]{southWest, southEast, northEast, northWest};

            south = new Line2D.Double(southWest, southEast);
            east = new Line2D.Double(southEast, northEast);
            north = new Line2D.Double(northWest, northEast);
            west = new Line2D.Double(southWest, northWest);
            walls = new Line2D.Double[]{south, east, north, west};
        }

    }

}
