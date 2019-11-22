using System;
using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;

namespace STAGIOPTR.MongoModels
{
    public class SensorTopic
    {
        [BsonId()]
        public ObjectId Id { get; set; }
        [BsonElement("dataHora")]
        [BsonRequired()]
        public DateTime DataHora { get; set; }
        [BsonElement("temperatura")]
        public double Temperatura { get; set; }
        [BsonElement("umidade")]
        public double Umidade { get; set; }
        [BsonElement("acelerometro")]
        public double Acelerometro { get; set; }
        [BsonElement("giroscopio")]
        public double Giroscopio { get; set; }
    }
}
