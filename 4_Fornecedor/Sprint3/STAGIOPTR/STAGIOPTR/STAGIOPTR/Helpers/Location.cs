using System;
using System.Diagnostics;
using Xamarin.Essentials;
using STAGIOPTR.Models;
using System.Threading.Tasks;

namespace STAGIOPTR.Helpers
{
    public static class Location
    {
        public static async Task<Coordinates> GetLocation()
        {
            try
            {
                var location = await Geolocation.GetLastKnownLocationAsync();

                if (location != null)
                {
                    //Debug.WriteLine($"Latitude: {location.Latitude}, Longitude: {location.Longitude}, Altitude: {location.Altitude}");
                    return new Coordinates
                    {
                        Latitude = location.Latitude,
                        Longitude = location.Longitude,
                        Altitude =(double) location.Altitude
                    };
                }
            }
            catch (FeatureNotSupportedException fnsEx)
            {
                Console.WriteLine("FeatureNotSupportedException" + fnsEx);
            }
            catch (FeatureNotEnabledException fneEx)
            {
                Console.WriteLine("FeatureNotEnabledException" + fneEx);
            }
            catch (PermissionException pEx)
            {
                Console.WriteLine("PermissionException" + pEx);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception" + ex);
            }

            return null;
        }
    }
}
