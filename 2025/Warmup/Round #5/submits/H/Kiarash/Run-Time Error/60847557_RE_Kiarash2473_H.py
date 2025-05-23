import numpy as np
from itertools import combinations

def compute_circumcenter(points):
    p = np.array(points)
    ref = p[0]
    A = 2 * (p[1:] - ref)
    b = np.sum(p[1:]**2, axis=1) - np.sum(ref**2)
    center_rel, _, _, _ = np.linalg.lstsq(A, b, rcond=None)
    return center_rel + ref

def max_distance(center, points):
    return max(np.linalg.norm(center - p) for p in points)

# Input
n = int(input())

points = []
for _ in range(n):
    coords = list(map(float, input().strip().split()))
    if len(coords) != 4:
        raise ValueError("Each point must have 4 coordinates.")
    points.append(np.array(coords))

# Initial setup
active_points = points[:min(n, 5)]
circumcenter = compute_circumcenter(active_points)
max_dist = max_distance(circumcenter, active_points)

# Iterative update
for i in range(len(active_points), n):
    new_point = points[i]
    new_dist = np.linalg.norm(new_point - circumcenter)

    if new_dist > max_dist:
        k = len(active_points)
        best_max_dist = float('inf')
        best_set = None

        for subset in combinations(active_points, k - 1):
            candidate = list(subset) + [new_point]
            center = compute_circumcenter(candidate)
            # Fixed comparison using np.array_equal
            all_points = candidate + [p for p in active_points if not any(np.array_equal(p, q) for q in subset)]
            dists = [np.linalg.norm(center - p) for p in all_points]
            candidate_max = max(dists)
            if candidate_max < best_max_dist:
                best_max_dist = candidate_max
                best_set = candidate
                best_center = center

        if best_set:
            active_points = best_set
            circumcenter = best_center
            max_dist = best_max_dist

# Output: space-separated coordinates of the circumcenter
print(" ".join(f"{x:.9f}" for x in circumcenter))
