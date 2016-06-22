
Set xl = CreateObject("Excel.Application")
Set wb = xl.Workbooks.Open("C:\Users\nathan.caron\Documents\PTRWorkSheet\Compare\Harpoon Phase RAN PTR List WIP V7.xlsx")
xl.DisplayAlerts = False

wb.SaveAs("C:\Users\nathan.caron\Documents\PTRWorkSheet\Compare\Harpoon_Unshared.xlsx")
On Error Resume Next
    wb.ExclusiveAccess()
wb.Close()
xl.Quit()
