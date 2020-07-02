# Grabs content of $filename which is test.ps1 & b64 encodes it & outputs it
# to copy output to clipboard use | clip
# execute b64 with powershell.exe -encodedCommand <b64>
$filename = "test.ps1"
$filecontent = get-content $filename -Raw
[Convert]::ToBase64String([System.Text.Encoding]::Unicode.GetBytes($filecontent))
