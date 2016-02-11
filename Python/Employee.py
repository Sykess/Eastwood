
import xml.dom.minidom
# from xml.dom.minidom import Node # Dunno why they added, not needed

userCount = 0
myDocument = xml.dom.minidom.parse("Employee1.xml")

for node in myDocument.getElementsByTagName("user"):
    userCount += 1

    username = node.getAttribute("name")
    userid = node.getAttribute("userid")

    print "User Name:  "+username
    print "User Id:    "+userid
print "User count:",userCount
print "User count: "+str(userCount) # Book recommends this way
