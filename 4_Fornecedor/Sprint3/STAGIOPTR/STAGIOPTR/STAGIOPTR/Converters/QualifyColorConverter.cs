using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class QualifyColorConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string qualify = (string)value;
            switch (qualify)
            {
                case "Ótimo":
                    return "#28a745";
                case "Bom":
                    return "#17a2b8";
                case "Regular":
                    return "#6c757d";
                case "Ruim":
                    return "#ffc107";
                case "Péssimo":
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
