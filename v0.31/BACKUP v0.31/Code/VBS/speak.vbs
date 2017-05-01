Set file = CreateObject("Scripting.FileSystemObject").OpenTextFile("G:\Code\VBS\testspeak.txt",1)
text = file.ReadAll()
file.Close
Set file = Nothing

Set VObj = CreateObject ("SAPI.SpVoice")
VObj.Speak text