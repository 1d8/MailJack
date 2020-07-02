# MailJack
## MADE FOR EDUCATIONAL/RESEARCH PURPOSES
***

# Explaining The Files

The test.ps1 file should include a link to the stealer.ps1 file, then you run b64encode.ps1, the output of b64encode.ps1 should be put inside the *b642* variable in dropper.c. Make sure to add `powershell -encodedCommand` before the base64 encoded data in the *b642* variable to ensure the base64 is decoded & executed.

Make sure to change the IP address & username & password used in stealer.ps1 to suit your own needs.


After execution of dropper.exe, we find that the infamous "hello world" phrase pops up in the command line & we see 2 new powershell scripts loaded onto the Desktop: file.ps1 & stealer.ps1:

![](/imgs/img3.png) 

Our process tree:

![](/imgs/img4.png)

So after execution of the dropper, Powershell is executed 4 times along with cmd.exe being executed 5 times.

We also see ping.exe being used twice which is used in order have the program sleep for a few seconds, in this case for about 10 & 5 seconds since it is asking for localhost to be pinged 10 & 5 times & each ping would take about a second, maybe even less:

![](/imgs/img5.png)

![](/imgs/img6.png)

The first instance of powershell is simply used to print "hello world":

![](/imgs/img7.png)

The second instance of powershell is used to execute file.ps1:

![](/imgs/img8.png)

Inside file.ps1 is just random hex, the same goes for stealer.ps1, the two files are likely modified after being executed:

![](/imgs/img9.png)

![](/imgs/img10.png)

Viewing the command in the Process Tree for file.ps1, we get a command that is base64 encoded twice. The 1st line is the double base64 encoded command while the 4th line is only base64 encoded once:

![](/imgs/img11.png)


`Powershell.exe -ExecutionPolicy bypass` is used to modify the execution policy of Powershell scripts which allows an attacker to execute their own scripts.

And the `--encodedCommand` flag simply decodes the base64 & executes it.

Decoding the 2nd base64, we see that file.ps1 retrieves the stealer.ps1 file:

![](/imgs/img12.png)

Setting the **ProgressPreference** to SilentlyContinue simply suppresses the output from the web request, usually web requests with powershell has a loading bar which shows the progress, example:

![](https://i2.wp.com/fredrikwall.se/wp-content/uploads/2020/01/image-14.png?resize=768%2C374&ssl=1)

For those who are unaware, notabug.org is a lot like Github, it allows you to host code and here, it hosts the primary malware:

![](/imgs/img13.png)

The first five lines of code:

1. Sets a **user** variable to the current user's username
2. Sets a **dir** variable to the user's temp directory + the user's username (%TMP%\Username)
3. Creates a directory using the **dir** variable & suppresses the output (the directory would be %TMP%\Username)
4. Searches for files with the .eml, .ost, .oft, or .msg extension recursively & adds the file to the folder created in line 3
5. Creates a zip file of the folder created in line 3, this folder should now contain files with common email extensions

Lines 6-17 simply send the zip file to a remote FTP server

Lines 18-19 remove the zip file as well as the folder created in the user's %TMP% directory

Now back to Process Tree since we have one remaining powershell.exe instance to look over:

![](/imgs/img14.png)

All this last instance of powershell does is finally execute stealer.ps1

# Summary

1. Dropper.exe will drop file.ps1 
2. File.ps1 includes a double base64 encoded command which will grab stealer.ps1
2. Stealer.ps1 will steal files with common email extensions & send them to a remote FTP server

# One last thing

If the user that executes dropper.exe has no email-related files on their system, they will get an ugly error:

![](/imgs/img15.png)
