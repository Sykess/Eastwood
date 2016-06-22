man test
#1465920718
man bash
#1465921424
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/Previous\ Spreadsheets/
#1465921450
ls "/cygdrive/y/WCS/Harpoon Phase Ran/Previous Spreadsheets"
#1465921530
if [ ! -a "/cygdrive/y/WCS/Harpoon Phase Ran/Previous Spreadsheets/Harpoon Phase RAN PTR List WIP V5.xlsx" ]; then echo "nope!"; fi
#1465921560
man bash
#1465921589
if [ ! -e "/cygdrive/y/WCS/Harpoon Phase Ran/Previous Spreadsheets/Harpoon Phase RAN PTR List WIP V5.xlsx" ]; then echo "nope!"; fi
#1465921606
if [ ! -e "/cygdrive/y/WCS/Harpoon Phase Ran/Previous Spreadsheets/Harpoon Phase RAN PTR List WIP V53.xlsx" ]; then echo "nope!"; fi
#1465921683
man bash
#1465921902
man mkdir
#1465921996
man cp
#1465922817
let "num = (( 200 || 11 ))"
#1465922819
echo $num
#1465923013
if [ 1 ]; then echo "hi"; fi
#1465923020
if [ 0 ]; then echo "hi"; fi
#1465923191
man bash
#1465923381
if /usr/bin/[ -z "hi"; then echo "yes!"; fi
#1465935615
echo $var
#1465935618
var=7
#1465935624
((var+=1))
#1465935627
echo $var
#1465935644
((var++))
#1465935646
echo $var
#1465935745
ls
#1465935756
mkdir bin
#1465935756
ls
#1465935757
cd bin
#1465935758
ls
#1465935766
vim TestAddition.sh
#1465936150
bash TestAddition.sh 
#1465937838
ls
#1465937880
ls
#1465937882
vim t0
#1465937906
vim TestAddition.sh
#1465937945
time ./t0
#1465937959
la
#1465937986
x=0
#1465938001
echo 'i=$((i+1))'
#1465938016
echo `i=$((i+1))`
#1465938036
echo 'x=$((x+1))'
#1465938112
echo '((x+=1))'
#1465938116
echo ((x+=1))
#1465938136
echo "((x+=1))"
#1465938191
echo -n 'x=$((x+1)) '
#1465938273
echo -n 'x=$((x+1)) '; { time ./t0 ;} |& grep user
#1465938334
man time
#1465938357
man bash
#1465938516
ls
#1465938521
cp t0 t0.backup
#1465938522
ls
#1465938532
vim t0
#1465938585
ls
#1465938588
la
#1465938601
time ./t0
#1465938619
time ./t0.backup
#1465938654
ls
#1465938661
rm t0~
#1465938662
ls
#1465939036
ls
#1465939044
rm t0
#1465939048
mv t0.backup t0
#1465939048
ls
#1465939054
du -sh
#1465939059
du -sh *
#1465939072
rm t*
#1465939073
ls
#1465939076
vim TestAddition.sh 
#1465939680
vim Output
#1465939722
ls
#1465939741
mkdir AdditionSpeed
#1465939742
ls
#1465939762
vimdiff TestAddition.sh*
#1465939773
ls
#1465939778
rm *~
#1465939779
ls
#1465939792
mv Output TestAddition.sh AdditionSpeed/
#1465939793
ls
#1465939795
ls AdditionSpeed/
#1465939804
cd AdditionSpeed/
#1465939805
ls
#1465939813
vim MyAttempt.sh
#1465940126
bash MyAttempt.sh 
#1465940144
vim MyAttempt.sh
#1465942637
ls
#1465942640
bash MyAttempt.sh
#1465942708
ls
#1465942709
vim output2 
#1465942757
ls
#1465942758
cd ..
#1465942759
ls
#1465942760
cd ..
#1465942760
ls
#1466000285
ls
#1466000287
vim UpdateAlliance.sh
#1466000308
vim Functions.sh
#1466014776
. Functions.sh
#1466014779
CopyWorksheet 
#1466014788
. Functions.sh
#1466014790
vim Functions.sh
#1466015459
CopyWorksheet 
#1466015464
. Functions.sh
#1466015466
CopyWorksheet 
#1466015477
. Functions.sh
#1466015479
vim Functions.sh
#1466015490
. Functions.sh
#1466015507
CopyWorksheet 
#1466015534
vim Functions.sh
#1466015639
. Functions.sh
#1466015641
CopyWorksheet 
#1466015660
vim Functions.sh
#1466015719
. Functions.sh
#1466015721
CopyWorksheet 
#1466015724
. Functions.sh
#1466015726
vim Functions.sh
#1466015819
. Functions.sh
#1466015824
CopyWorksheet 0
#1466015831
CopyWorksheet
#1466015836
vim Functions.sh
#1466015997
ls
#1466015999
. Functions.sh
#1466016004
CopyWorksheet 
#1466016012
CopyWorksheet
#1466016017
vim Functions.sh
#1466016029
. Functions.sh
#1466016031
CopyWorksheet
#1466016053
vim UpdateAlliance.sh
#1466016183
vim UpdateAlliance.sh
#1466016192
vim Functions.sh
#1466016197
getWorkbookVersion 
#1466016204
echo $version_num
#1466016232
vim UpdateAlliance.sh
#1466016288
bash UpdateAlliance.sh
#1466016301
. .bashrc
#1466016305
bash UpdateAlliance.sh
#1466016307
vim UpdateAlliance.sh
#1466016329
bash UpdateAlliance.sh
#1466016336
vim UpdateAlliance.sh
#1466016359
bash UpdateAlliance.sh
#1466016367
vim UpdateAlliance.sh
#1466016399
bash UpdateAlliance.sh
#1466086448
vim UpdateAlliance.sh
#1466095257
history
#1466095275
history | tail
#1466095296
cat HistoryFiles/Hist0616_3.txt 
#1466095334
ls
#1466095381
echo $blah
#1466095411
blah=5 && ((blah==6)) && echo hi
#1466095414
echo $blah
#1466095441
blah=5 && ((blah++)) && ((blah==6)) && echo hi
#1466095451
blah=5 && ((blah++)) && ((blah==0)) && echo hi
#1466095454
echo $blah
#1466095464
blah=5 && ((blah++)) && ((blah==0)) && echo hi || echo bye
#1466095466
echo $blah
#1466110026
cmd /c start /wait "C:\Users\nathan.caron\Documents\UnshareExcel.vbs"
#1465917826
ls
#1465917848
vim UpdateAlliance.sh
#1465917930
vim UnshareExcel.vbs
#1465917943
ls
#1465917956
pwd
#1465917967
gnome-open .
#1465918047
vim UpdateAlliance.sh
#1465918068
bash UpdateAlliance.sh
#1465918081
vim UpdateAlliance.sh
#1465918291
bash UpdateAlliance.sh
#1465918349
vim UpdateAlliance.sh
#1465918701
bash UpdateAlliance.sh
#1465918705
vim UpdateAlliance.sh
#1465918725
bash UpdateAlliance.sh
#1465918731
vim UpdateAlliance.sh
#1465918747
bash UpdateAlliance.sh
#1465918805
vim UpdateAlliance.sh
#1465919027
bash UpdateAlliance.sh
#1465919028
ls
#1465919034
vim UnshareExcel.vbs
#1465919045
vim CopySpreadsheet.sh
#1465919051
vim .bashrc
#1465919175
. .bashrc
#1465919176
ls
#1465919281
vim Functions.sh 
#1465919291
vim Functions.sh 
#1465919991
. Functions.sh
#1465919996
. Functions.sh
#1465919997
. Functions.sh
#1465919999
vim Functions.sh 
#1465920016
. Functions.sh
#1465920038
CopyWorksheet2 6
#1465920051
CopyWorksheet2
#1465920061
vim Functions.sh 
#1465920088
. Functions.sh
#1465920090
CopyWorksheet2
#1465920102
vim Functions.sh 
#1465920112
. Functions.sh
#1465920114
CopyWorksheet2
#1465920121
vim Functions.sh 
#1465920266
. Functions.sh
#1465920269
CopyWorksheet2
#1465920273
vim Functions.sh 
#1465920333
. Functions.sh
#1465920334
CopyWorksheet2
#1465920344
vim Functions.sh 
#1465920364
. Functions.sh
#1465920365
CopyWorksheet2
#1465920369
vim Functions.sh 
#1465920397
. Functions.sh
#1465920399
CopyWorksheet2
#1465920412
CopyWorksheet2 6
#1465920464
vim Functions.sh 
#1465921144
. Functions.sh
#1465921150
CopyWorksheet2 4
#1465921182
echo $?
#1465921188
CopyWorksheet2 5
#1465921192
echo $?
#1465921213
vim Functions.sh 
#1465921348
. Functions.sh
#1465921351
CopyWorksheet2 5
#1465921700
vim Functions.sh 
#1465921755
. Functions.sh
#1465921757
CopyWorksheet2 5
#1465921769
CopyWorksheet2 5
#1465921778
CopyWorksheet2 4
#1465921785
vim Functions.sh 
#1465922076
. Functions.sh
#1465922079
CopyWorksheet2 4
#1465922095
vim Functions.sh 
#1465922124
vim .bashrc
#1465922220
. .bashrc
#1465922221
ls
#1465922233
CopyWorksheet 
#1465922246
CopyWorksheet 4
#1465922254
vim Functions.sh
#1465922397
ls
#1465922403
vim CopySpreadsheet.sh
#1465922459
vim CopySpreadsheet.sh
#1465922542
vim Functions.sh
#1465939367
time for i in `seq 1 100000`; do ((i++)); done
#1465939379
time for i in `seq 1 1000000`; do ((i++)); done
#1465939396
time for i in `seq 1 1000000`; do ((i++)); done
#1465939439
time for i in `seq 1 1000000`; do let "i=i+1"; done
#1465939969
echo $i
#1465939972
i=1
#1465939990
i=$((i+1))
#1465939992
echo $i
#1465940041
echo -n 'i=$((i+1))  '; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user
#1465940397
echo -n 'i=$((i+1))  '; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user | tee testTee
#1465940406
ls
#1465940409
vim testTee 
#1465942194
vim testTee 
#1465942221
vim testTee 
#1465942239
echo -n 'i=$((i+1))  ' && { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user | tee testTee
#1465942287
vim testTee 
#1465942326
echo -n 'i=$((i+1))  ' >> testTee; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user | tee testTee
#1465942337
vim testTee 
#1465942342
man tee
#1465942356
echo -n 'i=$((i+1))  ' >> testTee; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user | tee -a testTee
#1465942368
vim testTee 
#1465942443
echo -n 'i=$((i+1))  ' >> testTee; { time for i in `seq 1 1000000`; do i=$((i+1)); done;} |& grep user >> testTee
#1465942450
vim testTee 
#1465942463
echo "" > testTee
#1465942466
vim testTee
#1466013726
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep "*V7.xlsx"
#1466013734
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/
#1466013747
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V7
#1466013791
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/
#1466013880
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V7.xlsx
#1466013922
blah=`ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V7.xlsx`
#1466013925
echo $blah
#1466013952
blah=6
#1466013970
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx
#1466013975
echo $blah
#1466014010
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah++)).xlsx
#1466014043
ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx
#1466014049
echo $blah
#1466014179
if [ ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx ]; then echo "hi"; fi
#1466014200
if [ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx` ]; then echo "hi"; fi
#1466014224
if [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx` ]]; then echo "hi"; fi
#1466014237
echo $blah
#1466014245
$((blah++))
#1466014257
((blah++))
#1466014259
echo $blah
#1466014276
if [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((blah+1)).xlsx` ]]; then echo "hi"; fi
#1466014381
ver="6"
#1466014419
until [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((ver+1)).xlsx` ]]; do ((ver++)); done
#1466014423
echo $ver
#1466014434
while [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((ver+1)).xlsx` ]]; do ((ver++)); done
#1466014439
echo $ver
#1466015855
unset blah
#1466015861
(($blah>3))
#1466086496
ls
#1466086500
vim CopySpreadsheet.sh
#1466086507
vim Functions.sh
#1466087175
local_copy='/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/Compare/Harpoon Phase RAN PTR List WIP V7.xlsx' 
#1466087213
current_worksheet='/cygdrive/y/WCS/Harpoon Phase RAN/'${filename}
#1466087241
current_worksheet='/cygdrive/y/WCS/Harpoon Phase RAN/Harpoon Phase RAN PTR List WIP V7.xlsx' 
#1466087249
echo $current_worksheet
#1466087253
echo $local_copy
#1466087297
bogus_copy='/cygdrive/c/Users/nathan.caron/Documents/Harpoon Phase RAN.xlsx'
#1466087321
[ -a "${local_copy}" ] && echo "exists"
#1466087371
[ -a "${local_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'` || local_md5="noFile"
#1466087380
echo $local_md5
#1466087417
[ -a "${bogus_copy}" ] && echo "exists"
#1466087453
[ -a "${bogus_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'` || local_md5="noFile"
#1466087456
echo $?
#1466087465
echo $local_md5
#1466087473
[ -a "${local_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'` || local_md5="noFile"
#1466087476
echo $local_md5
#1466087690
[ -e "${local_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'` || local_md5="noFile"
#1466087694
echo $local_md5
#1466087700
local_md5=ahh
#1466087702
echo $local_md5
#1466087704
[ -e "${local_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'` || local_md5="noFile"
#1466087705
echo $local_md5
#1466087758
[ -e "${current_worksheet}" ] && current_md5=`md5sum.exe "${current_worksheet}" | awk '{ print $1 }'` || current_md5="noFile"
#1466087764
echo $current_md5
#1466087801
[ $current_worksheet -eq $local_copy ] && echo "yup"
#1466087814
[[ $current_worksheet -eq $local_copy ]] && echo "yup"
#1466087922
[ "${current_worksheet}" == "${local_copy}" ] && echo "yup"
#1466087936
echo $current_worksheet
#1466087956
[ "${current_md5}" == "${local_md5}" ] && echo "yup"
#1466087963
[ "${current_md5}" -eq "${local_md5}" ] && echo "yup"
#1466087977
[[ "${current_md5}" -eq "${local_md5}" ]] && echo "yup"
#1466088039
cur=$current_md5
#1466088041
echo $cur
#1466088046
loc=$local_md5
#1466088048
echo $loc
#1466088064
[ "$cur" == "$loc" ]
#1466088067
echo $?
#1466088075
[ "$cur" == "$loc" ] && echo yes
#1466088081
[ "$cur" = "$loc" ] && echo yes
#1466088092
[ "$cur" -eq "$loc" ] && echo yes
#1466088103
[ "$cur" == "$loc" ] && echo yes
#1466088110
unset cur
#1466088112
[ "$cur" == "$loc" ] && echo yes
#1466088333
[ "$cur" == "$loc" ] && echo yes
#1466088341
[ "$cur" != "$loc" ] && echo yes
#1466088363
echo $cur
#1466088366
echo $loc
#1466088370
cur=$current_md5
#1466088372
echo $cur
#1466088463
[ "$cur" != "$loc" ] && echo not equal
#1466088482
cur=5
#1466088483
[ "$cur" != "$loc" ] && echo not equal
#1466088486
unset cur
#1466088487
[ "$cur" != "$loc" ] && echo not equal
#1466088502
[ $cur != $loc ] && echo not equal
#1466088507
cur=5
#1466088508
[ $cur != $loc ] && echo not equal
#1466090163
history | tee Hist0616.txt
#1466090219
vim Hist0616_2.txt 
#1466090291
ls
#1466090306
mkdir HistoryFiles
#1466090323
mv Hist0616* HistoryFiles/
#1466090327
ls HistoryFiles/
#1466090351
mkdir Tests
#1466090359
mv Test_* Tests
#1466090360
ls
#1466090369
vim testTee 
#1466090380
mv OldCopyUpdateAlly.sh Scripts/
#1466090385
ls
#1466090394
echo $VIM
#1466090398
echo $VIMRC
#1466090402
echo $MYVIMRC
#1466090404
ls
#1466090412
vim AddToSpreadsheet
#1466090419
vim AddToSpreadsheet~
#1466090433
ls
#1466090445
rm AddToSpreadsheet*
#1466090446
ls
#1466090449
vim awkTest 
#1466090462
mv awkTest Awk/
#1466090464
ls
#1466090552
rm V6.xlsx 
#1466090552
ls
#1466090560
mkdir Backup
#1466090563
mv *~ Backup/
#1466090564
ls
#1466090731
echo $current_worksheet
#1466090740
echo $local_worksheet
#1466090748
echo $local_copy
#1466090767
[ -e "${current_worksheet}" ] && echo exists
#1466090775
[ -e "${local_worksheet}" ] && echo exists
#1466090785
[ -e "${local_copy}" ] && echo exists
#1466091057
man run
#1466092008
man cygstart
#1466092308
man cmd
#1466092310
cmd
#1466092327
ls
#1466094674
ls
#1466094678
vim ImprovedUpdateAlliance.sh 
#1466099753
bash ImprovedUpdateAlliance.sh
#1466099777
bash ImprovedUpdateAlliance.sh
#1466099827
ls
#1466099846
mv UpdateAlliance.sh Scripts/OldUpdateAlliance.sh
#1466099854
mv ImprovedUpdateAlliance.sh UpdateAlliance.sh
#1466099854
ls
#1466110091
ls
#1466110093
vim UpdateAlliance.sh 
#1466446247
ls
#1466446254
mkdir Git
#1466446256
cd Git/
#1466446257
ls
#1466446271
git clone https://github.com/Sykess/Eastwood.git
#1466446661
git clone 
#1466446676
git clone git@github.com:Sykess/Eastwood.git
#1466446742
git config --global user.name
#1466446751
git config --global user.name "Sykess"
#1466446754
git config --global user.name
#1466446768
git config --global user.email "Sykess@users.noreply.github.com"
#1466446782
git config --global color.ui auto
#1466446802
git clone https://github.com/Sykess/Eastwood/git
#1466446812
git clone https://github.com/Sykess/Eastwood.git
#1466446884
git clone https://Sykess@github.com/Sykess/Eastwood.git
#1466447024
git config --global http.sslVerify false
#1466447037
git clone https://github.com/Sykess/Eastwood.git
#1466447051
ls
#1466447053
cd Eastwood/
#1466447054
ls
#1466447070
vim R
#1466447074
vim README.md 
#1466447103
git diff
#1466447143
git add README.md
#1466447155
git commit -m "Cygwin update"
#1466447168
git push origin master
#1466447362
vim .git/config 
#1466447462
curl --version
#1466447828
git push
#1466447973
echo $GIT_CURL_VERBOSE=1
#1466450526
pwd
#1466451387
ls
#1466451430
mkdir GitRepos
#1466451431
ls
#1466451524
cd GitRepos/
#1466451524
ls
#1466451526
cd Eastwood/
#1466451527
ls
#1466451529
vim README.md 
#1466451581
la
#1466451587
vim .gitignore
#1466451646
vim .gitignore
#1466451692
la
#1466452058
cdDoc 
#1466452060
ls
#1466452073
cd LinuxSync/
#1466452074
ls
#1466452105
tar -czf DotVimFolder.tar.gz dotVimFolder/
#1466452109
ls
#1466452114
du -sh DotVimFolder.tar.gz 
#1466452876
ls
#1466452912
tar -xzf DotVimFolder.tar.gz /home/nathan.caron/
#1466452927
ls
#1466452943
mv DotVimFolder.tar.gz ~
#1466452945
cd
#1466452945
ls
#1466452955
tar -xzf DotVimFolder.tar.gz .
#1466452959
tar -xzf DotVimFolder.tar.gz
#1466452962
ls
#1466452972
ls dotVim
#1466452976
ls dotVimFolder/
#1466452980
vim blah
#1466452990
la
#1466453025
rm -rf dotVim
#1466453030
rm -rf dotVimFolder/
#1466453031
ls
#1466453035
vim blah
#1466521924
exit
#1466449862
ls /var
#1466449867
ls /var/log/setup.log
#1466449872
vim /var/log/setup.log
#1466449922
ls
#1466449929
cd Git/Eastwood/
#1466449930
ls
#1466449939
git push origin master
#1466449959
curl
#1466449965
curl --version
#1466449992
set GIT_CURL_VERBOSE=1
#1466449996
git push
#1466450316
la
#1466450331
la /cygwin/c/Users
#1466450344
cd
#1466450344
ls
#1466450351
less UpdateAlliance.sh
#1466450388
la /cygdrive/c/Users/nathan.caron/
#1466450411
la
#1466450444
mkdir .ssh
#1466450448
vim .ssh/config
#1466521930
exit
#1466527376
sudo ls
#1466527380
passwd
#1466527395
ls
#1466527539
echo $LOGONSERVER
#1466527610
man passwd
#1466528967
exit
#1466613554
vim sieve.py
#1466613848
python
#1466614028
vim sieve.py 
#1466614132
python sieve.py 
#1466614165
vim sieve.py
#1466614215
python sieve.py 
#1466614220
vim sieve.py
#1466614230
python sieve.py 
#1466619185
python
