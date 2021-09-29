<?php

    /**
     * Saved database connection (already opened).
     * @var ?mysqli
     */
    $GLOBALS['.__database'] = null;

    /**
     * Path to folder that contains connection information.
     * @var string
     */
    $GLOBALS['.__database_path'] = null;
    
    /**
     * Initialize database library.
     * @param string $path Path to database files.
     */
    function __database(string $path)
    {
        $GLOBALS['.__database_path'] = $path;
        $GLOBALS['.__database'] = null;
    }

    /**
     * Open database connection.
     * @param string $name Name of th database connection to older (corresponds to the name in of the connection file).
     * @return ?mysqli Nullable mysqli object.
     */
    function database_open(string $name): ?mysqli
    {
        if ( null == $GLOBALS['.__database'] ?? null ){
            $file_include = sprintf('%s/mysqli-%s.ini', $GLOBALS['.__database_path'], $name);

            if (false == file_exists($file_include)) {
                throw new ErrorException("Unable to find database connection '{$name}' => {$file_include}.");
            }

            $config = parse_ini_file($file_include);
            $GLOBALS['.__database'] = mysqli_connect($config['host'] ?? null, $config['username'] ?? null, $config['password'] ?? null, $config['dbname'] ?? '', $config['port'] ?? '3306', $config['socket'] ?? null);

            if (false === $GLOBALS['.__database']) {
                $GLOBALS['.__database'] = null;
                throw new ErrorException("Unable to open database connection '{$name}'.");                
            }
        }
        return $GLOBALS['.__database'];
    }
    
