[ -z "$1" ] && status="update" || status="$1"
git add . && git commit -m "$status" && git push
