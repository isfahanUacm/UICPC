<?php

fscanf(STDIN, "%d", $n);
$T = array_map('intval', explode(' ', fgets(STDIN)));

$bestd = $bestt = 100;
for ($i = 0; $i < $n-2; ++$i) {
    $t = max($T[$i], $T[$i+2]);
    if ($t < $bestt) {
        $bestd = $i+1;
        $bestt = $t;
    }
}
printf("%d %d\n", $bestd, $bestt);
