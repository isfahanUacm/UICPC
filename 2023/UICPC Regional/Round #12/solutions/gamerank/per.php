<?php

$rank = 25;
$stars = 0;
$streak = 0;

function thres($rank) {
   return min(floor((35-$rank)/5), 5);
}

fscanf(STDIN, "%s", $results);

foreach (str_split($results) as $r) {
   if ($r == 'W') {
      $streak += 1;
      $stars += 1;
      if ($streak >= 3 && $rank > 5)
      	 $stars += 1;
      if ($stars > thres($rank) && $rank > 0) {
         $stars -= thres($rank);
	 $rank -= 1;
      }
   } else {
     $streak = 0;
     if (0 < $rank && $rank <= 20) {
     	$stars -= 1;
	if ($stars < 0) {
	   if ($rank < 20) {
	      $rank += 1;
	      $stars = thres($rank)-1;
	   } else {
	      $stars = 0;
	   }
	}
     }
   }
}

echo $rank ?: "Legend";
