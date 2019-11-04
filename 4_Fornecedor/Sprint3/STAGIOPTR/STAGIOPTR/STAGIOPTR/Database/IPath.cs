using System;
using System.Collections.Generic;
using System.Text;

namespace STAGIOPTR.Database
{
    public interface IPath
    {
        string GetPath(string DatabaseName);
    }
}
