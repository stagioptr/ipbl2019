using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class QualifyColorConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            int qualify = (int)value;
            switch (qualify)
            {
                case 5:
                    return "#28a745";
                case 4:
                    return "#17a2b8";
                case 3:
                    return "#6c757d";
                case 2:
                    return "#ffc107";
                case 1:
                    return "#dc3545";
                default:
                    return null;
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
