/* global getAssetRegistry getFactory emit */

/**
 * Notification transaction processor function.
 * @param {stagiopbd.notification.NotificationTransaction} tx The Notification transaction instance.
 * @transaction
 */
async function NotificationTransaction(tx) {  // eslint-disable-line no-unused-vars

    // Save the old value of the asset.
    const oldValue = tx.asset.value;

    // Update the asset with the new value.
    tx.asset.value = tx.newValue;

    // Get the asset registry for the asset.
    const assetRegistry = await getAssetRegistry('stagiopbd.notification.NotificationAsset');
    // Update the asset in the asset registry.
    await assetRegistry.update(tx.asset);

    // Emit an event for the modified asset.
    let event = getFactory().newEvent('stagiopbd.notification', 'NotificationEvent');
    event.asset = tx.asset;
    event.oldValue = oldValue;
    event.newValue = tx.newValue;
    emit(event);
}