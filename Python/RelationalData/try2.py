# initialize variables for the three main files
MasterOrders="MasterOrders.txt"
CustomerDetails="Customers.txt"
PurchaseOrders="PurchaseOrders.txt"

MastOrderIdDict     = {}
CustomerDetailsDict = {}
PurchaseOrdersDict  = {}

# iterate through the "customer details"
with open(CustomerDetails, 'rt') as f:
    for line in f:
        items = line.split()
        custDetailsId = items[0]
        CustomerDetailsDict[custDetailsId] = line

# iterate through the "purchase orders"
with open(PurchaseOrders, 'rt') as f:
    for line in f:
        items = line.split()
        poDetailsId = items[0]
        PurchaseOrdersDict[poDetailsId] = line

# iterate through the "master table"
with open(MasterOrders, 'rt') as f:
    for line in f:
        items = line.split()
        mastOrderId = items[1]

        # get the customer information
        custDetails = CustomerDetailsDict[mastOrderId]

        # get the id from the previous line
        custDetailsArr = custDetails.split()
        custDetailsId = custDetailsArr[0]

        # get the customer PO from the PO file
        custPOLine = PurchaseOrdersDict[custDetailsId]
        custPOArr = custPOLine.split()
        custPO=custPOArr[0]

        # print the details of the customer
        print 'Customer', mastOrderId,':'
        print 'Customer Details:',custDetails
        print 'Purchase Orders:',custPOLine
        print '----------------------'
