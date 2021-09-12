using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Goodreads
{
    public partial class GoodreadsForm : Form
    {
        GoodreadsValue grObject = new GoodreadsValue();
        public GoodreadsForm()
        {
            InitializeComponent();
            grObject.setIAmOn((double)numericUpDown1.Value);
            grObject.setMyTotal((double)numericUpDown2.Value);
            grObject.setGrTotal((double)numericUpDown3.Value);
            display();
        }

        void display()
        {
            int page = grObject.displayPage();
            label2.Text = page.ToString();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            grObject.setIAmOn((double)numericUpDown1.Value );
            display();
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            grObject.setMyTotal((double)numericUpDown2.Value);
            display();
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            grObject.setGrTotal((double)numericUpDown3.Value);
            display();
        }
    }
}