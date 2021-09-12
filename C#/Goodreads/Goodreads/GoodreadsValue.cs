using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Goodreads
{
    class GoodreadsValue
    {
        private double iAmOn, myTotal, grTotal;
        
        public void setIAmOn (double iAmOn)
        {
            this.iAmOn = iAmOn;
        }
        
        public void  setMyTotal (double myTotal)
        {
            this.myTotal = myTotal;
        }

        public void  setGrTotal (double grTotal)
        {
            this.grTotal = grTotal;
        }

        public int displayPage()
        {
            double x = (100.0 * iAmOn) / myTotal;
            int y = (int) ((grTotal * x) / 100.0);
            return y;
        }
    }
}
