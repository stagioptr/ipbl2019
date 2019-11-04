using System;
using System.Collections.Generic;
using System.Text;

namespace STAGIOPTR.ViewModels
{
    class MainViewModel : BaseViewModel
    {
        private int nome;

        public int Nome
        {
            get { return nome; }
            set { SetProperty(ref nome, value); }
        }

    }
}
