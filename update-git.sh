[ -z "$1" ] && status="update" || status="$1"
git add . && git commit -am "$status" && git push
