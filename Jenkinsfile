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

        stage('Deploy Executables') {
            steps {
                // Create a deployment directory
                sh 'mkdir -p deploy'

                // Move all compiled executables to the deployment directory
                sh 'mv *.exe ./deploy/'
            }
        }
    }

    post {
        success {
            echo 'Deployment completed successfully!'
            // Add further actions upon successful deployment
        }
        failure {
            echo 'Deployment failed!'
            // Add further actions upon deployment failure
        }
    }
}
