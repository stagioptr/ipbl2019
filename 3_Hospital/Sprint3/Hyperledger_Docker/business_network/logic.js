/**
 * Sensor transaction processor function.
 * @param {br.ita.stagioptr.SaveReadTransaction} tx The Sensor transaction instance.
 * @transaction
 */
async function SaveReadTransaction(tx) {  // eslint-disable-line no-unused-vars
    let factory = getFactory()
    const NS = 'br.ita.stagioptr'

    var sensor = factory.newResource(NS, 'Sensor', new Date().getTime().toString());
    sensor.topic = tx.topic;
    sensor.message = tx.message;
    sensor.datetime = tx.datetime;
    let sensorRegistry = await getParticipantRegistry(`${NS}.Sensor`);
    await sensorRegistry.add(sensor)

    // Emit an event for the modified asset.
    let event = getFactory().newEvent(NS, 'NewReadEvent');
    event.sensor = sensor;
    emit(event);
}