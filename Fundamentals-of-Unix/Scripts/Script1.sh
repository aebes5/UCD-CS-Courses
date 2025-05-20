file_name=$1 ; result_count=$2 ; cat "$file_name" | tr -s '[:space:]' '\n' | tr -d [:punct:] | tr [:upper:] [:lower:] | sort | uniq -c | sort -nr | head -"$result_count"
