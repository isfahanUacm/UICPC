/*
 * Reference solution for Airport Logistics.
 *
 * To compile:
 *   g++ -std=c++11 -Wall -O2 airport_solution.cc
 *
 * Time complexity O( N**2 * log(N) )
 *
 * This solution converts the input into a directed graph, with nodes
 * representing points on the floor and cost-labeled edges representing
 * the time to walk from one point to another. The final solution is
 * the shortest path from point A to point B within this graph.
 *
 * The construction of the graph depends on a few facts about this problem.
 *
 * Fact 1: The optimal path consists of straight line segments.
 *
 * Fact 2: When an optimal path joins a conveyor halfway (i.e. not at the
 * begin of the conveyor), this conveyor is approached via a straight line
 * intercepting the conveyor at a 60-degree angle. This is easily proved
 * by calculating the derivative of travel time as function of intercept angle.
 *
 * Fact 2b: When an optimal path leaves a conveyor halfway (i.e. not at the
 * end of the conveyor), the path leaves the conveyor via a straight line
 * at a 60-degree angle with the conveyor.
 *
 * Fact 3: It is never necessary to leave one conveyor halfway and join
 * the next conveyor halfway. There exists an optimal path which only joins
 * a conveyor halfway when coming straight from A or from the end of the
 * previous conveyor and which only leaves a conveyor halfway if the next
 * point is B or the begin of the next conveyor.
 *
 * Proof of fact 3:
 * Assume conveyors S and T with a path that leaves S halfway then joins T
 * halfway. The path segment from S to T over the floor must be straight
 * (fact 1), leave S with a 60-degree turn (fact 2b) and join T with
 * a 60-degree turn (fact 2).
 *
 * Consider first the case where the turn leaving S and the turn joining T
 * are in opposite directions. In this case the conveyors S and T are parallel.
 * It is obvious that the point of leaving S and the point of joining T can
 * both be shifted forward in the direction of the conveyors without changingi
 * the total path length. This process can continue until either the end of S
 * is reached or until the path segment on conveyor T is fully eliminated.
 * In either case, we find an equivalent path which either does not leave S
 * halfway or does not join T halfway. 
 *
 * Now consider the case where the turn leaving S and the turn joining T
 * are in the same direction. In this case, conveyors S and T and the path
 * segment from S to T form an equilateral triangle. Now shift the point of
 * leaving S forward along S by some distance D, and shift the point of
 * leaving T backward along T by the same distance D. This shortens the length
 * of the segment between S an d T by D. The resulting path travels 2*D more
 * distance over conveyors, but D less distance over the floor. The total cost
 * of the path is thus unchanged. This process can continue until either the
 * end of S or the beginnig of T is reached. In either case, we find an
 * equivalent path which either does not leave S halfway or does not join T
 * halfway.
 *
 * These facts support the construction of a graph with nodes for points A
 * and B, nodes representing the begin and end of each conveyor, and for
 * each conveyor a set of nodes representing the 60-degree intersection of
 * the conveyor with paths from A, B and any begin or end of any other
 * conveyor.
 *
 * This graph has O(N**2) nodes and O(N**2) edges in the worst case.
 * The shortest path in the graph is then found with Dijkstra's
 * algorithm in time O(E*log(E)).
 */

// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;


static constexpr double EPS = 1.0e-10;

struct Point { double x, y; };
struct Transport{ Point p1, p2; };

struct Edge {
    int dstnode;
    double len;
    Edge(int a_node, double a_len) : dstnode(a_node), len(a_len) { }
};

struct Node { vector<Edge> edges; };
struct Graph { vector<Node> nodes; };


/*
 * Find shortest path from start_node to end_node in specified graph.
 *
 * Use straightforward Dijkstra algorithm.
 */
double shortest_path(const Graph& graph, int start_node, int end_node)
{
    struct State {
        int node;
        double dist;
        State(int a_node, double a_dist) : node(a_node), dist(a_dist) { }
        bool operator<(const State& a) const { return dist > a.dist; }
    };

    vector<bool> node_reached(graph.nodes.size(), false);
    priority_queue<State> pq;

    // Put start_node in queue.
    pq.push(State(start_node, 0.0));

    // Explore graph until end_node found.
    while (!pq.empty()) {

        // Take closest node from queue.
        State st = pq.top();
        pq.pop();

        if (!node_reached[st.node]) {

            // Mark newly discovered node as reached.
            node_reached[st.node] = true;

            // Stop if this is the target node.
            if (st.node == end_node) {
                return st.dist;
            }

            // Put outgoing edges from this node on the queue.
            for (const auto& edge : graph.nodes[st.node].edges) {
                if (!node_reached[edge.dstnode]) {
                    pq.push(State(edge.dstnode, st.dist + edge.len));
                }
            }
        }
    }

    // There is no path from start_node to end_node.
    return INFINITY;
}


/*
 * Distance between points.
 */
double point_dist(const Point& a, const Point& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


/*
 * Calculate point X on the line through points V1 and V2, such that
 * there is a 60 degree angle between the vector from V1 to V2 and
 * the vector from P to X. This angle may be positive or negative 60 degrees.
 *
 * Return pdist: distance from point P to point X.
 * Return vfrac: distance from point V1 to point X as a fraction of distance
 *               between V1 and V2.
 *
 * Note that the intersection may occur outside the segment V1 - V2,
 * in that case vfrac will be negative or greater than 1.0.
 *
 * Points V1 and V2 are assumed to be different.
 */
void point_to_line(const Point& p, const Point& v1, const Point& v2,
                   double *pdist, double *vfrac)
{
    assert(fabs(v1.x - v2.x) > EPS || fabs(v1.y - v2.y) > EPS);

    const double sin60 = 0.5 * sqrt(3);
    const double cos60 = 0.5;

    // Determine (Vdx, Vdy) = vector from V1 to V2.
    double vdx = v2.x - v1.x;
    double vdy = v2.y - v1.y;

    // Determine (Pdx, Pdy) = vector from V1 to P.
    double pdx = p.x - v1.x;
    double pdy = p.y - v1.y;

    // Construct (Hdx, Hdy) = (Vdx, Vdy) rotated by 60 degrees.
    double hdx = vdx * cos60 - vdy * sin60;
    double hdy = vdy * cos60 + vdx * sin60;

    // Solve (Pdx, Pdy) = vf * (Vdx, Vdy) - hf * (Hdx, Hdy)
    double vf = (pdx * hdy - pdy * hdx) / (vdx * hdy - vdy * hdx);
    double hf = - (pdy * vdx - pdx * vdy) / (vdx * hdy - vdy * hdx);
    if (hf < 0) {
        // Point P is on the wrong side of line V1 - V2.
        // Rotate by 60 degrees in opposite direction.
        hdx = vdx * cos60 + vdy * sin60;
        hdy = vdy * cos60 - vdx * sin60;
        vf = (pdx * hdy - pdy * hdx) / (vdx * hdy - vdy * hdx);
        hf = - (pdy * vdx - pdx * vdy) / (vdx * hdy - vdy * hdx);
    }

    *pdist = hf * sqrt(hdx * hdx + hdy * hdy);
    *vfrac = vf;
}


/* Solve the problem. */
double solve(const Point& a, const Point& b,
             const vector<Transport>& transports)
{
    // Construct a graph.
    Graph graph;

    // Create node 0 to represent point A.
    // Create node 1 to represent point B.
    graph.nodes.insert(graph.nodes.end(), 2, Node());

    // Add the straight line from point A to point B.
    graph.nodes[0].edges.push_back(Edge(1, point_dist(a, b)));

    // Create even-index nodes 2..(2*N) to represent start points of transports.
    // Create odd-index nodes 3..(2*N+1) to represent end points of transports.
    int ntransport = transports.size();
    graph.nodes.insert(graph.nodes.end(), 2 * ntransport, Node());

    // Consider each transport.
    for (int k = 0; k < ntransport; k++) {

        // Build a list of points on this transport.
        vector<pair<double,int>> midpoints;

        // Add begin and end of transport to list of points.
        midpoints.push_back(make_pair(0.0, 2*k+2));
        midpoints.push_back(make_pair(1.0, 2*k+3));

        // Create a list of points from which one may want to walk
        // towards this transport. This includes point A as well as all
        // end points of other transports.
        vector<pair<int,Point>> active_nodes;
        active_nodes.push_back(make_pair(0, a));
        for (int q = 0; q < ntransport; q++) {
            if (q != k) {
                active_nodes.push_back(make_pair(2*q+3, transports[q].p2));
            }
        }

        // Consider each of the above points.
        for (const auto& active_node : active_nodes) {
            int srcnode    = active_node.first;
            Point srcpoint = active_node.second;

            // Consider a straight line from srcpoint to this transport.
            double pdist, vfrac;
            point_to_line(srcpoint, transports[k].p1, transports[k].p2,
                          &pdist, &vfrac);

            if (vfrac <= 0.0) {
                // The optimal route from srcpoint to this transport is
                // through the begin of this transport.
                pdist = point_dist(srcpoint, transports[k].p1);
                graph.nodes[srcnode].edges.push_back(Edge(2*k+2, pdist));
            } else if (vfrac < 1.0) {
                // The optimal route from srcpoint to this transport is
                // through a point on the middle of this transport.
                // Create a new node.
                int nn = graph.nodes.size();
                graph.nodes.push_back(Node());
                graph.nodes[srcnode].edges.push_back(Edge(nn, pdist));
                midpoints.push_back(make_pair(vfrac, nn));
            } else {
                // Coming from srcnode, this transport is not useful.
            }
        }

        // Create a list of points to which one may want to walk
        // coming from this transport. This includes point B as well as all
        // begin points of other transports.
        active_nodes.clear();
        active_nodes.push_back(make_pair(1, b));
        for (int q = 0; q < ntransport; q++) {
            if (q != k) {
                active_nodes.push_back(make_pair(2*q+2, transports[q].p1));
            }
        }

        // Consider each of the above points.
        for (const auto& active_node : active_nodes) {
            int dstnode    = active_node.first;
            Point dstpoint = active_node.second;

            // Consider a straight line from this transport to dstpoint.
            double pdist, vfrac;
            point_to_line(dstpoint, transports[k].p2, transports[k].p1,
                          &pdist, &vfrac);
            vfrac = 1.0 - vfrac;

            if (vfrac >= 1.0) {
                // The optimal route from this transport to dstpoint is
                // through the end of this transport.
                // Note: We may have already added this edge as part
                // of processing of the other transport. No problem, our
                // shortest path algorithm handles multi-edges.
                pdist = point_dist(transports[k].p2, dstpoint);
                graph.nodes[2*k+3].edges.push_back(Edge(dstnode, pdist));
            } else if (vfrac > 0.0) {
                // The optimal route from this transport to dstpoint is
                // through a point on the middle of this transport.
                // Create a new node.
                int nn = graph.nodes.size();
                graph.nodes.push_back(Node());
                graph.nodes[nn].edges.push_back(Edge(dstnode, pdist));
                midpoints.push_back(make_pair(vfrac, nn));
            } else {
                // This transport is not useful to get to dstpoint.
            }
        }

        // Nodes were created for begin and end of this transport, as well
        // as for a number of middle points. These nodes were connected to
        // the outside world, but not yet to each other. We must now create
        // intra-transport edges to represent the paths which use this
        // transport.

        // Sort points on transport from begin to end.
        sort(midpoints.begin(), midpoints.end());

        // Create intra-transport edges.
        for (int q = 1, n = midpoints.size(); q < n; q++) {
            int srcnode = midpoints[q-1].second;
            int dstnode = midpoints[q].second;
            double dist = (midpoints[q].first - midpoints[q-1].first) *
                          point_dist(transports[k].p1, transports[k].p2);
            graph.nodes[srcnode].edges.push_back(Edge(dstnode, 0.5 * dist));
        }
    }

    // Find shortest path from node A to node B in graph.
    return shortest_path(graph, 0, 1);
}


int main(void)
{
    Point a, b;

    // Read input.
    scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
    assert(a.x >= 0 && a.x <= 1000);
    assert(a.y >= 0 && a.y <= 1000);
    assert(b.x >= 0 && b.x <= 1000);
    assert(b.y >= 0 && b.y <= 1000);
    assert(fabs(a.x - b.x) > EPS || fabs(a.y - b.y) > EPS);

    int ntransport = -1;
    scanf("%d", &ntransport);
    assert(ntransport >= 0 && ntransport <= 100);

    vector<Transport> transports(ntransport);
    for (int i = 0; i < ntransport; i++) {
        double pdist, vfrac;
        Transport& t = transports[i];
        scanf("%lf %lf %lf %lf", &t.p1.x, &t.p1.y, &t.p2.x, &t.p2.y);
        assert(t.p1.x >= 0 && t.p1.x <= 1000);
        assert(t.p1.y >= 0 && t.p1.y <= 1000);
        assert(t.p2.x >= 0 && t.p2.x <= 1000);
        assert(t.p2.y >= 0 && t.p2.y <= 1000);
        // Check transport length.
        assert(point_dist(t.p1, t.p2) > 1.0);
        // Check transport does not intersect any earlier transport.
        for (int k = 0; k < i; k++) {
            Transport& tt = transports[k];
            point_to_line(t.p1, tt.p1, tt.p2, &pdist, &vfrac);
            assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
            point_to_line(t.p2, tt.p1, tt.p2, &pdist, &vfrac);
            assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
            point_to_line(tt.p1, t.p1, t.p2, &pdist, &vfrac);
            assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
            point_to_line(tt.p2, t.p1, t.p2, &pdist, &vfrac);
            assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
            double v1, v2;
            v1 = (tt.p1.x - t.p2.x) * (t.p2.y - t.p1.y) -
                 (t.p2.x - t.p1.x)  * (tt.p1.y - t.p2.y);
            v2 = (tt.p2.x - t.p2.x) * (t.p2.y - t.p1.y) -
                 (t.p2.x - t.p1.x)  * (tt.p2.y - t.p2.y);
            if (v1 * v2 < 0) {
                v1 = (t.p1.x - tt.p2.x) * (tt.p2.y - tt.p1.y) -
                     (tt.p2.x - tt.p1.x)  * (t.p1.y - tt.p2.y);
                v2 = (t.p2.x - tt.p2.x) * (tt.p2.y - tt.p1.y) -
                     (tt.p2.x - tt.p1.x)  * (t.p2.y - tt.p2.y);
            }
            assert(v1 * v2 >= 0);
        }
        // Check start point not on transport.
        point_to_line(a, t.p1, t.p2, &pdist, &vfrac);
        assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
        // Check end point not on transport.
        point_to_line(b, t.p1, t.p2, &pdist, &vfrac);
        assert(pdist > EPS || vfrac < -EPS || vfrac > 1.0 + EPS);
    }

    // Solve problem.
    double answer = solve(a, b, transports);

    // Write answer.
    printf("%.6f\n", answer);

    return 0;
}

