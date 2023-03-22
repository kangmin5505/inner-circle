make

./tests | awk '{$1=""; print }' >> result.txt
cat 19920104_091532.log | awk '{$1=""; print }' >> log.txt
diff result.txt log.txt

rm result.txt log.txt
make fclean
