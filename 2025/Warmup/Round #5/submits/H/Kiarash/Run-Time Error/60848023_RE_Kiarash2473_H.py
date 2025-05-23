import numpy as np
from itertools import combinations

# ---------- helpers ----------------------------------------------------------
def affine_rank(pts, tol=1e-12):
    """Affine (span) rank of a point cloud."""
    if len(pts) <= 1:
        return 0
    M = np.stack(pts)
    M -= M[0]                       # translate so p0 is the origin
    return np.linalg.matrix_rank(M, tol=tol)

def compute_circumcenter(pts, tol=1e-12):
    """
    Circum-centre of ≤5 points in ℝᴰ, even if they are singular
    (i.e. lie in a lower-dimensional affine sub-space).

    Returns (centre, rank) where `rank` is the affine dimension.
    """
    P = np.asarray(pts, dtype=float)
    k, D = P.shape

    if k == 1:                              # zero-dimensional
        return P[0], 0

    ref  = P[0]
    diff = P[1:] - ref
    r    = np.linalg.matrix_rank(diff, tol=tol)     # affine dimension

    if r == 0:                              # all points identical
        return ref, 0

    # -------- full-rank (non-singular) case ---------------------------------
    if r == k - 1:                          # rank matches the (k-1) rows
        A = 2 * diff
        b = np.sum(P[1:]**2, axis=1) - np.sum(ref**2)
        centre_rel, *_ = np.linalg.lstsq(A, b, rcond=None)
        return ref + centre_rel, r

    # -------- singular case: work in the r-D span ---------------------------
    # orthonormal basis of span{pᵢ − p₀}
    U, S, Vt = np.linalg.svd(diff, full_matrices=False)
    basis = Vt[:r].T                       # D × r

    coords = diff @ basis                  # coordinates in lower dim
    A_low  = 2 * coords
    b_low  = np.sum(coords**2, axis=1)

    centre_coords, *_ = np.linalg.lstsq(A_low, b_low, rcond=None)
    centre = ref + basis @ centre_coords
    return centre, r

def max_distance(c, pts):
    return max(np.linalg.norm(c - p) for p in pts)

# ---------- main programme ---------------------------------------------------
n = int(input())
points = [np.array(list(map(float, input().split()))) for _ in range(n)]

# seed the active set with (up to) 5 points
active = points[:min(n, 5)]
centre, act_rank = compute_circumcenter(active)
radius = max_distance(centre, active)

# streaming update for every remaining point ----------------------------
for p in points[len(active):]:
    d = np.linalg.norm(p - centre)
    if d <= radius + 1e-12:                # still covered – nothing to do
        continue

    k = len(active)

    # ---------- greedy “drop one, add p” search ----------------------------
    best_radius = float('inf')
    best_set    = None
    best_centre = None

    for subset in combinations(active, k - 1):
        cand = list(subset) + [p]
        c, _ = compute_circumcenter(cand)
        r    = max_distance(c, cand)
        if r < best_radius - 1e-12:
            best_radius, best_set, best_centre = r, cand, c

    # ---------- what if the new point raises the dimension? ---------------
    enlarged = active + [p]
    if len(enlarged) <= 5:                 # keep the 5-point cap
        c_big, rank_big = compute_circumcenter(enlarged)
        r_big = max_distance(c_big, enlarged)

        # choose this if it both improves the radius *and*
        # really jumps to a higher affine dimension
        if rank_big > act_rank and r_big < best_radius - 1e-12:
            best_radius, best_set, best_centre = r_big, enlarged, c_big

    # ---------- commit the best option ------------------------------------
    if best_set is not None:
        active   = best_set
        centre   = best_centre
        radius   = best_radius
        act_rank = affine_rank(active)

# output: coordinates of the final circum-centre
print(" ".join(f"{x:.9f}" for x in centre))
