# This file doesn't work properly
import xml.dom.minidom
from xml.dom.minidom import Node

userCount = 0
nodeName = ''
userName = ''
userid = ''

myDocument = xml.dom.minidom.parse("Employee2.xml")

for node in myDocument.getElementsByTagName("user"):
    userCount += 1

for subNode in node.childNodes:
    if(subNode.nodeType == subNode.ELEMENT_NODE):
        nodeName = subNode.nodeName

        if(subNode.firstChild != None):
            nodeContents = subNode.firstChild.nodeValue

            if(nodeName == "name"):
                userName =  nodeContents;

            elif(nodeName == "userid"):
                userid   =  nodeContents;

    print "User Name:   "+userName
    print "User Id:     "+userid
    print "--------------------\n"

print "User count:  "+str(userCount)
