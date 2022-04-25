path="C:\\Development\\C++\\Pferderennen"
declare -a Tests=("CardDeckTest" "DrawCardTest")

input=""

for test in ${Tests[@]}; do
	OpenCppCoverage.exe --sources $path\\src --export_type=binary:$test.cov -- $path\\build\\Debug\\$test.exe
	input="$input--input_coverage=$test.cov "
done

OpenCppCoverage.exe --sources $path\\src $input -- $path\\build\\app\\Debug\\Main.exe
