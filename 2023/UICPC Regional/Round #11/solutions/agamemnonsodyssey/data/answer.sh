for i in secret/*.in
do
	echo "running ${i%.*}.ans"
    ./nalin < $i > ${i%.*}.ans
    echo "wrote ${i%.*}.ans"
done
