CREATE TABLE users (
        id          INT PRIMARY KEY AUTO_INCREMENT,
        nombre      VARCHAR(32),
        correo      VARCHAR(64)
);

CREATE TABLE services (
        id          INT PRIMARY KEY AUTO_INCREMENT,
        nombre      VARCHAR(32),
        descripcion TEXT,
        img         VARCHAR(16),
        cant        INT
);

INSERT INTO services (nombre, descripcion, img, cant) VALUES ("Reparacion de celular", "Reparacion de fallos tanto fisicos como de software de tu dispositivo celular", "s1.svg", 0), ("Reparacion de laptop", "Reparacion de fallos tanto fisicos como de software de tu laptop", "s2.svg", 0), ("Reparacion de impresora", "Reparacion de fallos tanto fisicos como de software de tu dispositivo de impresion", "s3.svg", 0), ("Reparacion de electrodomesticos", "Reparacion de fallos fisicos en tus electrodomesticos", "s4.svg", 0), ("Ayuda para uso de electronicos", "Te ayudamos cuando tienes problemas para usar tus dispositivos electronicos", "s5.svg", 0);

CREATE TABLE orders (
        id          INT PRIMARY KEY AUTO_INCREMENT,
        nombre      VARCHAR(32),
        telefono    VARCHAR(16),
        direccion   VARCHAR(64),
        id_servicio   INT,
        FOREIGN KEY (id_servicio) REFERENCES services(id)
);
