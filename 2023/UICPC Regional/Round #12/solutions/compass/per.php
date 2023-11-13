<?php

fscanf(STDIN, "%d", $n1);
fscanf(STDIN, "%d", $n2);
$n2 -= $n1;
if ($n2 > 180) $n2 -= 360;
if ($n2 <= -180) $n2 += 360;
echo $n2;
