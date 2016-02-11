class counter
{
    private:
        double total;
        bool overFlow;
     private:
        void checkOver()
        { 
            if(total > 99.99)
            {
                overFlow = true;
                total -= 100;
            }
        }    
    public:
        counter()
        {
            resetCounter();
        } 
        //mutator's  
        void addPenny()
        {
            total += 0.01;
            checkOver();
        }
        void addNickle()
        {
            total += 0.05;
            checkOver();
        }
        void addDime()
        {
            total += 0.10;
            checkOver();
        }
        void addQuarter()
        {
            total += 0.25;
            checkOver();
        }
        void resetCounter()
        {
            total = 0;
            overFlow = false;
        }
        //accessor's
        bool getTotal(double & tot)
        {
            tot = total;
            return !overFlow;
        }
};
