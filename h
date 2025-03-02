<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Charles University Entrance Exam Registration</title>
    <script src="https://www.paypal.com/sdk/js?client-id=AcHLRMtMsQR6vIW3uRfg9ReLUaoHWEPEe1MqPCm1C5R0V-nf_Kyn0xcanhn81_cG3UND8zcLMNlkG3nf&components=buttons"></script>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; padding: 20px; }
        form { max-width: 400px; margin: auto; background: #f4f4f4; padding: 20px; border-radius: 10px; }
        input, button { width: 100%; padding: 10px; margin: 10px 0; }
    </style>
</head>
<body>
    <h2>Charles University Entrance Exam Registration</h2>
    <form id="registrationForm">
        <input type="text" id="name" placeholder="Full Name" required>
        <input type="email" id="email" placeholder="Email" required>
        <input type="text" id="passport" placeholder="Passport Number" required>
        <button type="submit">Register</button>
    </form>
    
    <h3>Pay the Exam Fee</h3>
    <div id="paypal-button-container"></div>
    
    <script>
        document.getElementById('registrationForm').addEventListener('submit', function(event) {
            event.preventDefault();
            alert('Registration submitted! Proceed with payment.');
        });
        
        paypal.Buttons({
            createOrder: function(data, actions) {
                return actions.order.create({
                    purchase_units: [{ amount: { value: '250' } }] // Change price accordingly
                });
            },
            onApprove: function(data, actions) {
                return actions.order.capture().then(function(details) {
                    alert('Payment successful! Thank you, ' + details.payer.name.given_name);
                });
            }
        }).render('#paypal-button-container');
    </script>
</body>
</html>
