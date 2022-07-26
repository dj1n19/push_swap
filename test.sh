#!/bin/zsh
AVG=0
for i in $(seq 0 $2)
do
    ARGS=$(ruby generator.rb $1)
    echo "ARGS: $ARGS"
    echo $(./push_swap $ARGS | wc -l)
    AVG=$(($AVG + $(./push_swap $ARGS | wc -l | tr -d " ")))
    ./push_swap $ARGS | ./checker_Mac $ARGS
done
AVG=$(($AVG/$2))
echo "AVG: $AVG"