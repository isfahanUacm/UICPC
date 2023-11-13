<?php

fscanf(STDIN, "%d %d", $n, $p);
$best = 1.0*$p/($n+1);
$prod = $best;
for ($m = 2; $m <= $n+1; ++$m) {
    $prod *= 1.0*($n-$p+$m)/($n+$m);
    $val = $prod*$m;
    if ($val > $best)
       $best = $val;
    else
       break;
}
echo $best;
