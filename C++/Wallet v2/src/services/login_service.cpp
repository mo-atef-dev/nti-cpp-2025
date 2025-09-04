#include "login_service.h"
#include "repository_exceptions.h"

LoginService::LoginService(Application &appliction)
{
    m_application = &appliction;
    m_userRepository = m_application->GetUserRepository();
}

bool LoginService::Login(std::string userName, std::string password)
{
    try
    {
        // Search the repository for the username
        User u = m_userRepository->GetByName(userName);

        // Check if the password matches
        if(u.GetPassword() == password)
        {
            /**
             * If the password is correct then I set the current user
             * by sending a pointer to a new user object allocated with
             * new and is a copy of u
             * 
             * Since the application stores the user with a unique_ptr
             * it will handle its release
             */
            m_application->SetCurrentUser(new User{u});
            return true;
        }

        return false;
    }
    catch(const not_found& e)
    {
        return false;
    }
}
