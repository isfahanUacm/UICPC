for i in {1..30}
do
    rand1=$(perl -e 'print int(rand(10**9))')
    rand2=$(perl -e 'print int(1+rand(100))')
    printf "$rand1 $rand2\n"
    printf "$rand1 $rand2\n" > rand-med$i.in
done
