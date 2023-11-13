<?php

fscanf(STDIN, "%d", $days);
$money = 100;
$prev = 1<<30;
for ($i = 0; $i < $days; ++$i) {
    fscanf(STDIN, "%d", $cur);
    if ($cur > $prev)
       $money += min(floor($money/$prev), 100000)*($cur-$prev);
    $prev = $cur;       	      	 		   
}
echo $money;
