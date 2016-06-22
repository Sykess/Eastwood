#!/bin/bash

x=0
until [ $x = "1000000" ]; do
    echo 'i=$((i+1))' >> t0
    echo '((i=i+1))' >> t1
    echo '((i+=1))' >> t2
    echo '((i++))' >> t3
    echo 'let "i=i+1"' >> t4
    echo 'let "i+=1"' >> t5
    echo 'let "i++"' >> t6
    echo '((++i))' >> t7
    ((x++))
done

chmod +x t0 t1 t2 t3 t4 t5 t6 t7
echo -n 'i=$((i+1)) '; { time ./t0 ;} |& grep user
echo -n '((i=i+1))  '; { time ./t1 ;} |& grep user
echo -n '((i+=1))   '; { time ./t2 ;} |& grep user
echo -n '((i++))    '; { time ./t3 ;} |& grep user
echo -n 'let "i=i+1"'; { time ./t4 ;} |& grep user
echo -n 'let "i+=1" '; { time ./t5 ;} |& grep user
echo -n 'let "i++"  '; { time ./t6 ;} |& grep user
echo -n '((++i))    '; { time ./t7 ;} |& grep user

rm t0 t1 t2 t3 t4 t5 t6 t7
