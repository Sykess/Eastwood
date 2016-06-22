#!/bin/bash

echo -n 'i=$((i+1))  ' > output2; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user >> output2
echo -n '((i=i+1))   ' >> output2; { time for i in `seq 1 1000000`; do ((i=i+1)); done;}  |& grep user >> output2
echo -n '((i+=1))    ' >> output2; { time for i in `seq 1 1000000`; do ((i+=1)); done;}   |& grep user >> output2
echo -n '((i++))     ' >> output2; { time for i in `seq 1 1000000`; do ((i++)); done;}    |& grep user >> output2
echo -n 'let "i=i+1" ' >> output2; { time for i in `seq 1 1000000`; do let "i=i+1"; done;}|& grep user >> output2
echo -n 'let "i+=1"  ' >> output2; { time for i in `seq 1 1000000`; do let "i+=1"; done;} |& grep user >> output2
echo -n 'let "i++"   ' >> output2; { time for i in `seq 1 1000000`; do let "i++"; done;}  |& grep user >> output2
echo -n '((++i))     ' >> output2; { time for i in `seq 1 1000000`; do ((++i)); done;}    |& grep user >> output2
