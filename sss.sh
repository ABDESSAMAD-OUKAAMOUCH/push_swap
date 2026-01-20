# #!/bin/bash

# # عدد المحاولات العشوائية
# RUNS=1000
# LIMIT=5500

# # ملفات مؤقتة
# RESULTS="results.txt"
# > $RESULTS  # نفضي الملف

# # تكرار الاختبارات
# for i in $(seq 1 $RUNS); do
#   # إنشاء 500 رقم عشوائي بين 1 و 1000
#   ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
  
#   # حساب عدد العمليات
#   OPS=$(./a.out $ARG | wc -l)
  
#   # تخزين النتيجة
#   echo $OPS >> $RESULTS
  
#   # فحص إذا تجاوز الحد
#   if [ $OPS -gt $LIMIT ]; then
#     echo "⚠️ Run $i exceeded limit: $OPS operations"
#     # يمكنك أيضًا طباعة الأرقام إذا أحببت
#     # echo $ARG
#   fi
# done

# # حساب الإحصائيات
# MIN=$(sort -n $RESULTS | head -n 1)
# MAX=$(sort -n $RESULTS | tail -n 1)
# SUM=$(awk '{s+=$1} END {print s}' $RESULTS)
# AVG=$(awk '{s+=$1} END {printf "%.2f", s/NR}' $RESULTS)

# echo ""
# echo "📊 Summary for $RUNS runs:"
# echo "Minimum operations: $MIN"
# echo "Maximum operations: $MAX"
# echo "Average operations: $AVG"


# RUNS=1000
# LIMIT=5500
# RESULTS="results.txt"
# > $RESULTS

# # 1️⃣ اختبارات عشوائية
# echo "Running $RUNS random tests..."
# for i in $(seq 1 $RUNS); do
#   ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
#   OPS=$(./a.out $ARG | wc -l)
#   echo $OPS >> $RESULTS
#   if [ $OPS -gt $LIMIT ]; then
#     echo "⚠️ Random Run $i exceeded limit: $OPS operations"
#   fi
# done

# # 2️⃣ أسوأ حالة: تنازلي
# echo "Running worst-case (descending order)..."
# ARG=$(seq 500 -1 1 | tr '\n' ' ')
# OPS=$(./a.out $ARG | wc -l)
# echo $OPS >> $RESULTS
# if [ $OPS -gt $LIMIT ]; then
#   echo "⚠️ Worst-case exceeded limit: $OPS operations"
# fi

# # 3️⃣ الملخص الإحصائي
# MIN=$(sort -n $RESULTS | head -n 1)
# MAX=$(sort -n $RESULTS | tail -n 1)
# AVG=$(awk '{s+=$1} END {printf "%.2f", s/NR}' $RESULTS)

# echo ""
# echo "📊 Summary (Random + Worst-case):"
# echo "Minimum operations: $MIN"
# echo "Maximum operations: $MAX"
# echo "Average operations: $AVG"
#!/bin/bash

OUTER_RUNS=10     # عدد تكرار الاختبار الكامل
RUNS=1000         # عدد الاختبارات العشوائية في كل مرة
LIMIT=5500

for round in $(seq 1 $OUTER_RUNS); do
  echo ""
  echo "=============================="
  echo "🔁 Test Round $round / $OUTER_RUNS"
  echo "=============================="

  RESULTS="results_round_$round.txt"
  > $RESULTS

  # 1️⃣ اختبارات عشوائية
  echo "Running $RUNS random tests..."
  for i in $(seq 1 $RUNS); do
    ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' ')
    OPS=$(./a.out $ARG | wc -l)
    echo $OPS >> $RESULTS

    if [ $OPS -gt $LIMIT ]; then
      echo "⚠️ Random Run $i exceeded limit: $OPS operations"
      # echo "$ARG" > failed_round_${round}.txt
    fi
  done

  # 2️⃣ أسوأ حالة (تنازلي)
  echo "Running worst-case (descending order)..."
  ARG=$(seq 500 -1 1 | tr '\n' ' ')
  OPS=$(./a.out $ARG | wc -l)
  echo $OPS >> $RESULTS

  if [ $OPS -gt $LIMIT ]; then
    echo "⚠️ Worst-case exceeded limit: $OPS operations"
  fi

  # 3️⃣ الملخص
  MIN=$(sort -n $RESULTS | head -n 1)
  MAX=$(sort -n $RESULTS | tail -n 1)
  AVG=$(awk '{s+=$1} END {printf "%.2f", s/NR}' $RESULTS)

  echo ""
  echo "📊 Summary – Round $round:"
  echo "Minimum operations: $MIN"
  echo "Maximum operations: $MAX"
  echo "Average operations: $AVG"
done
