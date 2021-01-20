FT_QUIT=$(($FT_LINE2+1))
cat /etc/passwd | grep -o '^[^#].*' | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p ; $FT_QUIT q " | tr '\n' ',' | sed 's/,/, /g' | 
sed 's/, $/./' | tr -d '\n'