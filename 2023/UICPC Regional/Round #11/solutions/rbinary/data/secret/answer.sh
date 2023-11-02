for i in *.in
do
    ./bryce < $i > ${i%.*}.ans
    echo "wrote ${i%.*}.ans"
done
