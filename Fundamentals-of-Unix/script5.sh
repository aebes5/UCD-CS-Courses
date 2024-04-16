result_count=$1;

for file_name in "${@:2}"
do
	
	echo "=======($(wc -l -w -c $file_name) ====)";
	cat "$file_name" | tr -s '[:space:]' '\n' | tr -d [:punct:] | tr [:upper:] [:lower:] | sort | uniq -c | sort -nr | head -"$result_count";
done
