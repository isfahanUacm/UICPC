<?php
// PHP implementation of Andreas Björklunds solution

function freecol(&$adj, $n, $x) {
    $col = array();
	for ($i=0;$i<$n;$i++) $col[] = 0;
	for ($i=0;$i<$n;$i++)
		if ($adj[$x][$i]<0)
			$col[-$adj[$x][$i]]=1;
	for ($i=1;$i<$n && $col[$i];$i++);
	return -$i;
}

function locatecol(&$adj, $n, $x, $c) {
	for ($i=0;$i<$n && $adj[$x][$i]!==$c;$i++);
	return $i;
}

function recol(&$adj, $n, $x, $y) {
    $vis = array();
	$who = array();
	$wcol = array();
	$fy=freecol($adj, $n, $y);
	$nc=locatecol($adj, $n, $x,$fy);
	$cur = 1;
	for ($i=0;$i<$n;$i++) $vis[] = 0;
	$vis[$y] = 1;
	$who[0] = $y;
	$wcol[0] = $fy;
	while ($nc!=$n && !$vis[$nc]) {
		$vis[$nc] = 1;
		$y=$nc;
		$fy = freecol($adj, $n, $y);
		$who[$cur] = $y;
		$wcol[$cur++] = $fy;
		$nc = locatecol($adj, $n, $x, $fy);
	}

	if ($nc==$n) {
		for ($i=0;$i<$cur;$i++) {
			$adj[$x][$who[$i]] = $wcol[$i];
			$adj[$who[$i]][$x] = $wcol[$i];
		}
	} else {
		$fx = freecol($adj, $n, $x);
		$nn=locatecol($adj, $n, $nc,$fx);
		$adj[$x][$nc] = $fx;
		$adj[$nc][$x] = $fx;
		while ($nn!=$n) {
			$nnn= locatecol($adj, $n, $nn,$fy);
			$adj[$nc][$nn] = $fy;
			$adj[$nn][$nc] = $fy;
			$nc=$nn;
			$nn=$nnn;
			$tmp=$fx;
			$fx=$fy;
			$fy=$tmp;
		}
		recol($adj, $n, $x,$who[0]);
	}
}

function main() {
	$parts = explode(' ', fgets(STDIN));
	$n = (int) $parts[0];
	$m = (int) $parts[1];

	$adj = array();


	for($i=0;$i<$n;$i++) {
		for($j=0;$j<$m;$j++) {
			$adj[$j*$n+$i] = array();
			for($k=0;$k<$n;$k++) {
				for($l=0;$l<$m;$l++) {
					$adj[$j*$n+$i][$l*$n+$k] = $j !== $l;
				}
			}
		}
	}
	for($i=0;$i<$n*$m;$i++) {
		for($j=0;$j<$n*$m;$j++) {
			if ($adj[$i][$j] > 0) {
				recol($adj, $m*$n, $i, $j);
			}
		}
	}

	$matches = $n*($m-1)*$n*$m/2;
	for($k=1;$k<$n*($m-1)+2 && $matches;$k++) {
		for($i=0;$i<$n*$m;$i++) {
			for($j=$i+1;$j<$n*$m;$j++) {
				if ($adj[$i][$j] == -$k) {
					$matches--;
					printf("%c%d-%c%d ",65+($i/$n),($i%$n)+1,65+($j/$n),($j%$n)+1);
				}
			}
		}
		printf("\n");
	}
}

main();

?>
