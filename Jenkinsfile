pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Clone the Git repository
                git branch: 'main', url: 'https://github.com/imran-ikp/project-A.git'
            }
        }

        stage('Compile C files') {
            steps {
                // Get a list of all .c files in the repository
                script {
                    def files = sh(script: "find . -type f -name '*.c'", returnStdout: true).trim().split('\n')

                    // Iterate over each .c file and compile
                    files.each { file ->
                        def executableName = file.replaceAll('\\.c$', '')
                        sh "gcc -o ${executableName} ${file}"
                    }
                }
            }
        }
    }

    post {
        success {
            echo 'All C files compiled successfully!'
            // Add further actions upon successful compilation of all files
        }
        failure {
            echo 'Failed to compile one or more C files!'
            // Add further actions upon failure of any compilation
        }
    }
}
