using System;
using System.Collections.Generic;
using System.Text;

namespace StagioptrApp.Database
{
    public interface IPath
    {
        string GetPath(string DatabaseName);
    }
}
