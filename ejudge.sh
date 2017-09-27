#!/bin/sh
if [ "$#" -ne 3 ]
then
    echo "Usage: ./ejudge.sh [CONTEST_ID] [EJSID] [TASK_ID]"
    echo ""
    echo "CONTEST_ID can be obtained by goind to any problem in the contest and"
    echo "copying ejudge.ru/ej/user/view-problem-submit/[[THIS PART]]?prob_id=1"
    echo ""
    echo "EJSID is the session id cookie"
    echo ""
    echo "TASK_ID seems to be consequtively assigned, so the first task in the "
    echo "list has id 1 and so on"
else
    id=$(printf "%04d\n" $3)
    curl https://unicorn.ejudge.ru/ej/user/view-problem-submit/$1\?prob_id\=$3 -k --cookie "EJSID=$2" \
        | pcre2grep -Mo "<h3>(.|\n)*</h3>" \
        | pandoc -s -r html -o ejudge1/$id.md
    if [ "$(wc -m ejudge1/$id.md | grep -o '^[0-9]*')" -le 1 ]
    then
        rm "ejudge1/$id.md"
    fi
fi
