from uuid import uuid4
import paho.mqtt.client as mqtt
import time

def on_message(client, userdata, message):
    print(str(message.payload.decode("utf-8")))

def on_disconnect(client, userdata, rc=0):
    client.loop_stop()

broker_address = "broker.hivemq.com"

uuid = str(uuid4())

client = mqtt.Client(uuid)

client.on_message = on_message

client.on_disconnect = on_disconnect

client.connect(broker_address)

client.subscribe("real_unique_topic")

client.loop_forever()