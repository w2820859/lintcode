files=`find . -name "title"`
for file in $files
do
    echo $file"\t"`cat $file`
done
