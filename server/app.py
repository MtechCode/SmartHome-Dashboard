from flask import Flask, request, jsonify
from flask_cors import CORS
import json

app = Flask(__name__)
CORS(app)

data_storage = {"temperature": [], "humidity": []}

@app.route('/data', methods=['POST'])
def receive_data():
    data = request.json
    data_storage["temperature"].append(data["temperature"])
    data_storage["humidity"].append(data["humidity"])
    return jsonify({"status": "success"}), 200

@app.route('/latest-data', methods=['GET'])
def latest_data():
    return jsonify(data_storage), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
